#!/usr/bin/env python
import curses
import random
import time

try:
    screen = curses.initscr()
    curses.cbreak()
    curses.noecho()
    curses.curs_set(0)

    lines = 28
    gotoY = 27
    rounds = 0
    max_rounds = 10

    while True:
        rand = random.randrange(0,lines);
        currentline = random.randrange(0,lines);
        while rand == currentline:
            currentline = random.randrange(0,lines);
        rounds += 1

        message = "<- Go to this line"
        if rounds == 1:
            tic = time.perf_counter()
        elif rounds > max_rounds:
            message = "Gave Over!"
            currentline = int(lines / 2)
            rand = int(lines / 2)
            toc = time.perf_counter()
        message_hl = int(len(message) / 2)
        while True:
            if rounds == -1:
                rounds = 0
                break
            screen.clear()
            screen.addstr(0, 0, "VIM Be Good!  :")
            if rounds < max_rounds + 1:
                screen.addstr(0, 17, "Round " + str(rounds) + " / 10")
            else:
                screen.addstr(0, 17, "Round 10 / 10")
                timer = "Time: " + str(round(( toc - tic ), 2)) + "s"
                timer_hl = int(len(timer) / 2)
                screen.addstr(4 + rand, gotoY - timer_hl, timer)
                end_message1 = "Press <q> to exit"
                end_message2 = "Press <ENTER> to play again"
                end_message1_hl = int(len(end_message1) / 2)
                end_message2_hl = int(len(end_message2) / 2)
                screen.addstr(6 + rand, gotoY - end_message1_hl, end_message1)
                screen.addstr(7 + rand, gotoY - end_message2_hl, end_message2)

            if currentline < 0:
                currentline = 0
            elif currentline > lines:
                currentline = lines 
            
            for i in list(range(currentline)):
                var = currentline - i
                num =  str(var)
                padding = 1
                if var  < 10:
                    padding = 2
                if i == rand:
                    screen.addstr(3 + i, gotoY - message_hl, message)
                screen.addstr(3 + i, padding, num)

            screen.addstr(3 + currentline, 0, str(currentline + 1))
            screen.addstr(3 + currentline, 4, " ", curses.A_REVERSE)
            if currentline == rand:
                screen.addstr(3 + currentline, gotoY - message_hl, message)
            
            for i in list(range(currentline,lines)):
                var = i - currentline + 1
                num = str(var)
                padding = 1
                if var  < 10:
                    padding = 2
                if i + 1 == rand:
                    screen.addstr(4 + i, gotoY - message_hl, message)
                screen.addstr(4 + i, padding, num)
                screen.refresh()
            if currentline == rand and rounds < max_rounds + 1:
                curses.napms(300)
                break

            keys=0
            while True:
                c = screen.getch()
                if keys < 0:
                    keys = 0
                elif keys > lines:
                    keys = lines 
                    
                if c == ord('j'):
                    if keys > 0: 
                        currentline += keys
                    else:
                        currentline += 1
                    break
                elif c == ord('k'):
                    if keys > 0: 
                        currentline -= keys
                    else:
                        currentline -= 1
                    break
                elif c == curses.KEY_ENTER or c == 10 or c == 13:
                    if rounds > max_rounds:
                        rounds = -1
                        break
                elif c == ord('q'):
                    exit(0)       
                elif c == ord('1'):
                    if keys > 0:
                        keys = int(str(keys)+"1")
                    else:
                        keys = 1
                elif c == ord('2'):
                    if keys > 0:
                        keys = int(str(keys)+"2")
                    else:
                        keys = 2
                elif c == ord('3'):
                    if keys > 0:
                        keys = int(str(keys)+"3")
                    else:
                        keys = 3
                elif c == ord('4'):
                    if keys > 0:
                        keys = int(str(keys)+"4")
                    else:
                        keys = 4
                elif c == ord('5'):
                    if keys > 0:
                        keys = int(str(keys)+"5")
                    else:
                        keys = 5
                elif c == ord('6'):
                    if keys > 0:
                        keys = int(str(keys)+"6")
                    else:
                        keys = 6
                elif c == ord('7'):
                    if keys > 0:
                        keys = int(str(keys)+"7")
                    else:
                        keys = 7
                elif c == ord('8'):
                    if keys > 0:
                        keys = int(str(keys)+"8")
                    else:
                        keys = 8
                elif c == ord('9'):
                    if keys > 0:
                        keys = int(str(keys)+"9")
                    else:
                        keys = 9
                elif c == ord('0'):
                    if keys > 0:
                        keys = int(str(keys)+"0")
                    else:
                        keys = 0


finally:
    # Standard shutdown. Probably don't need to change this.
    curses.nocbreak()
    curses.echo()
    curses.endwin()

