# 2. Require an initialization subcommand to configure RAD for a directory

## Status

| Status   | Time                         |
| -------- | ---------------------------- |
| Accepted | 2024-09-26T22:15:37.8243876Z |

## Context

We do not know where this application will be ran.

Similar to Git and Talo, we want the user to be able to instantiate the
application in any directory.

## Decision

Therefore, it is in the user's best interest to manually run the `init` command
to configure a directory as the top level project directory with a `.rad` file.

This `.rad` file will be in a structured, serialized format like TOML or JSON.
The type of file will be added to the filename as the extension (i.e.
`.rad.toml`)

## Consequences

Wherever the nearest `.rad` file is within the filesystem hierarchy, it is
considered the top level directory w.r.t the program's functionality.

The application will have to recursively move up the file hierarchy looking for
the `.rad` file to know where to store new ADRs or show the status field of
ADRs.
