# 7. Recursively move back through parent directories to find .rad.json files

## Status

| Status   | Time                         |
| -------- | ---------------------------- |
| Accepted | 2024-10-04T17:27:45.5380476Z |

## Context

`rad` should be able to be executed anywhere within the project structure to
create ADRs like `git`. But to do so, it needs to identify the nearest
`.rad.json` file to know where to store ADRs.

## Decision

An algorithm will be added to the `ConfigFile` class to identify where the
nearest `.rad.json` file is.

The algorithm will work by:

1. List files in current directory
1. If `.rad.json` exists, return path to `.rad.json`
1. Else, change directory to the immediate parent directory
1. Repeat

## Consequences

All directories will be checked, a smarter algorithm will only consider paths
that the user has read and write access to.
