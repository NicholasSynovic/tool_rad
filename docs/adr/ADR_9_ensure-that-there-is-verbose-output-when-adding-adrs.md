# 9. Ensure that there is verbose output when adding ADRs

## Context

The user should know if an ADR:

- has been created, and
- where it has been created

## Decision

`rad` will print out the fullpath of the new ADR upon creation.

## Consequences

`rad` will be considered a "noisy" application where it spits out verbose
output.
