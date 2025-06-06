#!/usr/bin/env python3
"""
Compute average and median runtimes from @brief annotations.

Usage:
    1. conda env update --file environment.yml  --prune
    2. java installed
    3. F5
"""

from __future__ import annotations

import re
import statistics
from datetime import datetime
from typing import Optional, Tuple, List

from pyspark.sql import SparkSession


PATH_GLOB = "{leetcode,Cracking the Coding Interview}/**/*"

BRIEF_PATTERN = re.compile(
    r"@brief\s+"
    r"(?:(?P<hours>\d+)\s*hrs?\s*)?"
    r"(?:(?P<minutes>\d+)\s*m\s*)?"
    r"(?:(?P<seconds>\d+)\s*s)?",
    re.IGNORECASE,
)

SECONDS_IN_MIN = 60
SECONDS_IN_HOUR = 60 * SECONDS_IN_MIN

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
        print(f"{CLR_YELLOW}⚠ No match: {line.strip()}{CLR_RESET}")
        return None

    h = int(match.group("hours") or 0)
    m = int(match.group("minutes") or 0)
    s = int(match.group("seconds") or 0)

    return h * SECONDS_IN_HOUR + m * SECONDS_IN_MIN + s


def humanize(seconds: float) -> str:
    minutes, secs = divmod(int(seconds), SECONDS_IN_MIN)
    return f"{minutes} m {secs} s"


def compute_runtime_stats() -> Tuple[int, int]:
    spark = SparkSession.builder.appName("brief-stats").getOrCreate()
    sc = spark.sparkContext

    times = (
        sc.textFile(PATH_GLOB)
        .filter(lambda line: "@brief" in line)
        .map(parse_brief)
        .filter(lambda sec: sec is not None)
    )

    if times.isEmpty():
        print("No valid @brief timings found.")
        spark.stop()
        return

    avg_sec = times.mean()
    median_sec = statistics.median(times.collect())

    matched_file_count = times.count()
    spark.stop()

    return avg_sec, median_sec, matched_file_count


def main() -> None:
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    avg_sec, med_sec, matched_files_count = compute_runtime_stats()

    # |                     | Problems | Average  | Median    |
    # | ------------------- | -------- | -------- | --------- |
    # | 2025-04-12 12:25:09 | 50       | 31 m 0 s | 23 m 45 s |
    # print("")
    # print(f"{CLR_BOLD}{CLR_CYAN}LeetCode Timing Stats{CLR_RESET} ({timestamp})")
    # print(f"{CLR_BOLD}{CLR_CYAN}{timestamp}{CLR_RESET}")
    # print(f"{CLR_GREEN}Problems     :{CLR_RESET} {matched_files_count}")
    # print(f"{CLR_GREEN}Average Time :{CLR_RESET} {humanize(avg_sec)}")
    # print(f"{CLR_GREEN}Median Time  :{CLR_RESET} {humanize(med_sec)}")
    print(
        f"| {CLR_BOLD}{CLR_CYAN}{'Date':<19}{CLR_RESET} | "
        f"{CLR_BOLD}{CLR_CYAN}{'Problems':<8}{CLR_RESET} | "
        f"{CLR_BOLD}{CLR_CYAN}{'Average':<9}{CLR_RESET} | "
        f"{CLR_BOLD}{CLR_CYAN}{'Median':<9}{CLR_RESET} |"
    )
    print(f"| ------------------- | -------- | --------- | --------- |")
    print(
        f"| {timestamp:<19} | "
        f"{CLR_YELLOW}{str(matched_files_count):<8}{CLR_RESET} | "
        f"{CLR_RED}{humanize(avg_sec):<9}{CLR_RESET} | "
        f"{CLR_GREEN}{humanize(med_sec):<9}{CLR_RESET} |"
    )


if __name__ == "__main__":  # pragma: no cover
    main()
