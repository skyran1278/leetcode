---
name: commit-message
description: Use when generating git commit messages from a diff - produces Conventional Commits 1.0.0 compliant messages with structured body and type classification
---

# Commit Message Generator

## Overview

Generate commit messages strictly following Conventional Commits 1.0.0 and the rules below.

Input: a git diff. Output: a single commit message.

## Format

```
<type>[optional scope]: <short description>

- explain the motivation behind this change
```

## Type Choices

Use one of: `fix`, `feat`, `build`, `chore`, `ci`, `docs`, `style`, `refactor`, `perf`, `test`

- `feat`: adds a new feature
- `fix`: represents a bug fix
- `BREAKING CHANGE`: add `!` before `:` in type/scope, or include `BREAKING CHANGE:` footer

## Guidelines

**description:**
- imperative, present tense, lowercase start, no period
- immediately follows the colon and space

**body** (include by default; omit only for trivial changes like typo fixes):
- blank line after description
- use dashes (`-`) for bullet points
- imperative, present tense, lowercase start, no period
- each line ≤ 80 characters
- explain the motivation (WHY), not just what changed

**footer (optional):**
- one blank line after body
- token format: `Token: value` or `Token #value`
- `BREAKING CHANGE` MUST be uppercase

## Example

```
fix(auth): add refresh token logic

- users were unexpectedly logged out when token expired silently
```

## Validation Checklist

- [ ] type is one of the allowed types
- [ ] scope (if used) is a noun in parentheses
- [ ] description is lowercase, imperative, no trailing period
- [ ] body begins with a blank line after description
- [ ] every line ≤ 80 characters
- [ ] breaking changes marked with `!` or `BREAKING CHANGE:` footer

## Common Mistakes

| Mistake | Fix |
|---------|-----|
| `feat: Added new button` | `feat: add new button` (imperative, lowercase) |
| `fix: fixed bug.` | `fix: fix bug` (no period, imperative) |
| Body immediately after description | Add blank line between description and body |
| Line > 80 chars | Break into multiple lines |
| `breaking change:` in footer | Must be `BREAKING CHANGE:` (uppercase) |
| No body on non-trivial change | Add body explaining motivation (WHY) |
