# 11. Validate config file with JSON schema prior to executing code

## Context

The `.rad.json` file can contain any number of key-value pairings. However, the
functionality of `rad` is dependent upon there being a set of required keys
present within the config file. To ensure that these keys exist, the content of
the JSON file can be validated against a JSON Schema to ensure the presence of
the necessary keys.

## Decision

We will use the sourcemeta organizations `blaze` library for validating JSON
Schemas.

## Consequences

When creating new fields for the ADR, both the schema and the default config
will have to be updated. Additionally, this information will have to be
documented within the `README.md` file.
