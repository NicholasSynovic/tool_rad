# 5. Utilize JSON over YAML

## Status

| Status   | Time                         |
| -------- | ---------------------------- |
| Accepted | 2024-09-27T18:42:53.7899444Z |

## Context

We need to serialize our configuration to disk.

YAML format is common and well understood, however, finding a well documented
YAML library has been challenging.

We should pivot to utilizing a different serialization format such as JSON that
has a well documented library.

## Decision

We will switch to JSON and leverage the `nlohmann/json` library.

- [https://github.com/nlohmann/json](https://github.com/nlohmann/json)

## Consequences

So far none, we just need to convert YAML discussions to JSON.
