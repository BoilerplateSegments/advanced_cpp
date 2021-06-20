file(READ "./README.md" NICE)
file(READ "/proc/cmdline" CL)
message(${NICE})
message(${CL})
