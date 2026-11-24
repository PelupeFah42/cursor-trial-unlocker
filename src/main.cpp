// main.cpp — entry point. Wires config and subsystems together.

#include "cursortrialunlocker/settings.h"
#include "cursortrialunlocker/resetter.h"
#include "cursortrialunlocker/fingerprint.h"
#include "cursortrialunlocker/backup.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    cursortrialunlocker::Settings settings = cursortrialunlocker::Settings::load_default();
    cursortrialunlocker::Resetter resetter(settings.store_path);
    cursortrialunlocker::Fingerprint fingerprint(settings.store_path);
    cursortrialunlocker::Backup backup(settings.store_path);
    std::fprintf(stderr, "[cursor-trial-unlocker] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
