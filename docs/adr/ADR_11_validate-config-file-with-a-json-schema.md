# 11. Validate config file with a JSON schema

## Context

A user can put anything within the `.rad.json` file. This results in the user
potentially misconfiguring their config file degrading the experience of using
`rad`. Furthermore, the application currently makes 0 checks that the data
within the config file is the expected format. Thus an integer could be passed
to a `Path` type resulting in an error. Finally, keys are not checked within the
config file. This results in the application crashing from trying to find keys
that may or may not be within the file.

## Decision

We will leverage a *JSON Schema* validation library to validate the config file
JSON at all parts of the toolchain:

- creation,
- modification, and
- loading

## Consequences

We will have to replace the current JSON library and update the config file test
suite to accomodate the JSON Schema impelmentation. Additionally, adding new
config options and features will result in having to modfiy the JSON Schema
along with the code implementation.
