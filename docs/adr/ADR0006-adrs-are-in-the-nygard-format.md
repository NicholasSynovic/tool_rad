# 6. ADRs are in the Nygard format

## Status

| Status   | Time                         |
| -------- | ---------------------------- |
| Accepted | 2024-10-03T21:31:27.7716736Z |

## Context

ADRs can come in various formats. As such, the user can be overwhelmed by the
variety of styles. It would be best from engineering and a usability standpoint
to default to well known template.

## Decision

The default template should be Nygard template as described by Michael Nygard in
their
[Documenting Architecture Decisions](https://cognitect.com/blog/2011/11/15/documenting-architecture-decisions)
blog post.

## Consequences

For now, we do not need to implement an interface for multiple different ADR
templates. However, if we do support multiple templates in the future, we will
need to implement an interface to simplify testing and development.

Most likely, the interface will inherit the functionality of the Nygard class.
