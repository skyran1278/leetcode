#!/usr/bin/env python3
"""
Compute average and median runtimes from @brief annotations.

Usage:
    1. uv run scripts/timing_stats.py
"""

from __future__ import annotations

import os
import re
import statistics
from datetime import datetime
from pathlib import Path
from typing import NamedTuple, Optional

ROOTS = ("leetcode", "Cracking the Coding Interview", "Hello Algo")
EXTS = (".cpp", ".py", ".ts", ".js")

BRIEF_PATTERN = re.compile(
    r"@brief\s*"
    r"(?:(?P<hours>\d+)\s*hrs?\s*)?"
    r"(?:(?P<minutes>\d+)\s*m\s*)?"
    r"(?:(?P<seconds>\d+)\s*s)?",
    re.IGNORECASE,
)

# @brief lines carrying any of these tags are excluded from baseline stats.
# See CLAUDE.md for the tagging convention.
TAGS_TO_SKIP = ("(editorial)", "(recall)", "(untimed)")

SECONDS_IN_MIN = 60
SECONDS_IN_HOUR = 60 * SECONDS_IN_MIN


class BriefStats(NamedTuple):
    avg_sec: float
    median_sec: float
    attempts: int
    unique_problems: int
    editorial: int


def problem_dir(path: str) -> str:
    return os.path.dirname(path)

# ANSI colors (no external dependency)
CLR_RESET = "\033[0m"
CLR_BOLD = "\033[1m"
CLR_GREEN = "\033[32m"
CLR_CYAN = "\033[36m"
CLR_YELLOW = "\033[33m"
CLR_RED = "\033[31m"


def parse_brief(line: str) -> Optional[int]:
    """
    Extract timing (in seconds) from an @brief annotation in a line.
    """
    match = BRIEF_PATTERN.search(line)
    if not match:
        print(f"{CLR_RED}⚠ No match: {line.strip()}{CLR_RESET}")
        return None

    h = int(match.group("hours") or 0)
    m = int(match.group("minutes") or 0)
    s = int(match.group("seconds") or 0)

    return h * SECONDS_IN_HOUR + m * SECONDS_IN_MIN + s


def humanize(seconds: float | int) -> str:
    """Render seconds as a human-readable m/s string.

    Accepts int or float; value is truncated toward zero for display granularity.
    """
    minutes, secs = divmod(int(seconds), SECONDS_IN_MIN)
    return f"{minutes} m {secs} s"


def compute_runtime_stats() -> BriefStats:
    pairs: list[tuple[str, str]] = []
    for root in ROOTS:
        for path in Path(root).rglob("*"):
            if path.suffix not in EXTS or not path.is_file():
                continue
            text = path.read_text(encoding="utf-8", errors="replace")
            path_str = str(path)
            for line in text.splitlines():
                if "@brief" in line:
                    pairs.append((path_str, line))

    clean = [pl for pl in pairs if not any(tag in pl[1] for tag in TAGS_TO_SKIP)]
    editorial_count = sum(1 for pl in pairs if "(editorial)" in pl[1])

    times = [sec for _, line in clean if (sec := parse_brief(line)) is not None]

    if not times:
        print("No valid @brief timings found.")
        return BriefStats(0.0, 0.0, 0, 0, 0)

    avg_sec = statistics.mean(times)
    median_sec = float(statistics.median(times))
    attempts = len(clean)
    unique_problems = len({problem_dir(p) for p, _ in clean})

    return BriefStats(avg_sec, median_sec, attempts, unique_problems, editorial_count)


def main() -> None:
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    stats = compute_runtime_stats()

    print(
        f"| {CLR_BOLD}{CLR_CYAN}{'Date':<19}{CLR_RESET} | "
        f"{CLR_BOLD}{CLR_CYAN}{'Problems':<8}{CLR_RESET} | "
        f"{CLR_BOLD}{CLR_CYAN}{'Attempts':<8}{CLR_RESET} | "
        f"{CLR_BOLD}{CLR_CYAN}{'Editorial':<9}{CLR_RESET} | "
        f"{CLR_BOLD}{CLR_CYAN}{'Average':<9}{CLR_RESET} | "
        f"{CLR_BOLD}{CLR_CYAN}{'Median':<9}{CLR_RESET} |"
    )
    print(
        "| ------------------- | -------- | -------- | --------- | --------- | --------- |"
    )
    print(
        f"| {timestamp:<19} | "
        f"{CLR_YELLOW}{str(stats.unique_problems):<8}{CLR_RESET} | "
        f"{CLR_YELLOW}{str(stats.attempts):<8}{CLR_RESET} | "
        f"{CLR_YELLOW}{str(stats.editorial):<9}{CLR_RESET} | "
        f"{CLR_RED}{humanize(stats.avg_sec):<9}{CLR_RESET} | "
        f"{CLR_GREEN}{humanize(stats.median_sec):<9}{CLR_RESET} |"
    )


if __name__ == "__main__":  # pragma: no cover
    main()
