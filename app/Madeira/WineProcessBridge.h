#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Start Wine process initialization on a background thread.
// Must be called AFTER wineserver is running.
// prefix_path: path to the Wine prefix directory
// Returns 0 on success, -1 on error.
int wine_process_start(const char *prefix_path);

// Check if Wine process is running
int wine_process_is_running(void);

// Steam S0 net-test VPN gate: write C:\madeira-continue.flag into the
// prefix's drive_c so the paused winhttp-test.exe resumes to the Steam
// stage. Called by the "Continue Net Test" UI button after the user has
// detached the JIT debugger and switched VPNs. Returns 0 on success.
int madeira_write_continue_flag(void);

// Mount a host folder as an additional Wine drive letter by (re)creating
// dosdevices/<drive_letter>: -> host_path in the prefix. drive_letter is a
// single ASCII letter (case-insensitive); "c" is reserved for drive_c and
// should not be passed here. Safe to call multiple times (overwrites any
// existing link at that letter). Returns 0 on success, -1 on error.
int madeira_mount_drive(const char *prefix_path, const char *drive_letter, const char *host_path);

#ifdef __cplusplus
}
#endif
