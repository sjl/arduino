#!/usr/bin/env bash

set -eu -o pipefail

./arduino arduino:avr:uno "$1"
