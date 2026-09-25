# Madeira

Run Windows PC games on a non-jailbroken iPhone.

Madeira combines [Wine](https://www.winehq.org/) (Aarch64),
[FEX-Emu](https://github.com/FEX-Emu/FEX) (ARM64EC) for x86-64 → ARM64 translation, and
[DXMT](https://github.com/3Shain/DXMT) for D3D11 → Metal, running as a single
Mach process on iOS with wineserver as a thread rather than a separate process.

## Status

Thumper and ULTRAKILL are playable. Marvel Cosmic Invasion has reached
gameplay, though a run has also ended in an unexplained termination and its
controls are not yet reliable. Others reach gameplay at low frame rates. This
is a research project, not a product: expect rough edges, per-title quirks and
breaking changes.

## Requirements

- A non-jailbroken iPhone. Development has been on an A15 (iPhone 13 Pro).
- JIT, which on iOS requires a debugger to attach —
  [StikDebug](https://github.com/0-Blu/StikJIT) is what this project uses.
- An Apple ID for signing. A free account works; its provisioning profiles
  expire after 7 days, so the app must be rebuilt and reinstalled weekly. The
  app's container survives reinstall, so prefixes and saves are preserved.

 JIT requires debugger attach, this app cannot be distributed through the
App Store. It is installed by sideloading.

## Features

- **Mounted folders.** The "Mount Folder" button opens the Files picker and
  maps a chosen folder into the Wine prefix as an additional drive letter
  (`D:`, `E:`, ...) alongside `C:`, so a game's assets or save data can live
  outside the app's own container. Mounts persist across launches via
  security-scoped bookmarks; remove one with a swipe in the "Mounted Folders"
  sheet.

## Building

The build is split across several chains — the unix-side Wine libraries, the
ARM64EC PE modules, FEX, DXMT and the iOS app itself. `build/*/build.sh` covers
the native pieces; the app is built with `xcodebuild`.

```sh
git clone --recurse-submodules <this repo>
