# 10. ADRs will inherit from a base Markdown class

## Context

We'd like to support different common ADR formats. Each format would be written
to a Markdown file. Rather than implementing the Markdown logic per file, it
would be best to have the Markdown file logic be handled by a Markdown class.

## Decision

A Markdown class will be created. This class will have logic for the following:

- Title
- Sections

## Consequences

The existing NygardADR class will have to be rewritten, along with its test, to
support inheriting from the Markdown class.
