# 5. RAD can create ADRs with add

## Status

| Status   | Time                         |
| -------- | ---------------------------- |
| Accepted | 2024-09-28T17:21:09.2559901Z |

## Context

The user should be able to use the `rad` executable to create ADRs.

## Decision

To create ADRs, the user can execute `rad add` and specify:

- The ADR title

ADR files will be in MarkDown format and the filename will be as follows:

`ADR_#_{title}.md`

## Consequences

When adding a ADR, the application will have to find the nearest `.rad.json`
file to know where to store the ADR.

If the ADR directory does not exist, the ADR will not be created and an error
will be thrown to inform the user.
