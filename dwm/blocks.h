#define PATH(name)                      "/home/amnesia/scripts/blocks/"name

/* If interval of a block is set to 0, the block will only be updated once at startup.
 * If interval is set to a negative value, the block will never be updated in the main loop.
 * Set pathc to NULL if clickability is not required for the block.
 * Set signal to 0 if both clickability and signaling are not required for the block.
 * Signal must be less than 10 for clickable blocks.
 * If multiple signals are pending, then the lowest numbered one will be delivered first. */

/* pathu - path of the program whose output is to be used for status text
 *         output of the program should have a null or newline character at the end
 * pathc - path of the program to be executed on clicks */

/* 1 interval = INTERVALs seconds, INTERVALn nanoseconds */
#define INTERVALs                       1
#define INTERVALn                       0

static Block blocks[] = {
/*      pathu                           pathc                                   interval        signal */
        { PATH("pacman.sh"),            PATH("pacman_button.sh"),               0,              8},
        { PATH("cpu_temp.sh"),          PATH("cpu_temp_button.sh"),             1,              4},
        { PATH("time.sh"),              PATH("time_button.sh"),                 1,              5},
        { PATH("keyboard.sh"),          PATH("keyboard_button.sh"),             0,              6},
        { NULL } /* just to mark the end of the array */
};

static const char *delim =  "   ";
