# 4. Have a class to manage the config file

## Status

| Status   | Time                         |
| -------- | ---------------------------- |
| Accepted | 2024-09-27T15:50:20.8346293Z |

## Context

The state of the `.rad` file should only be interfaced with - via the code - in
a standardized manner.

## Decision

We will create a `ConfigFile` class in a `classes/configFile.{cpp,h}` file.

This class will be responsible for the following CRU operations:

- Creating the config file in its initial state,
- Reading data from the config file into application memory, and
- Updating values in the config file

## Consequences

- The class will check if the config file exists
- The initial state of the config file will have to be hardcoded,
- The class will have to be able to check if the config file is in a valid
  format
- The class will have to handle the creation and identification of RAD config
  files
