int game(int ac, char **av)
{
    struct sigaction info;
    int player = -1;
    struct timespec sleep_time = {60, 0};

    init_sig(&info);
    if (ac == 3 && (av[1][0] >= '0' && av[1][0] <= '9')) {
        player = 1;
        enemy_pid = my_getnbr(av[1]);
        syncro(1);
    } else {
        syncro(0);
        player = 2;
    } while (GAME.win == -1) {
	if (player == 1) {
            write(1, "attack:  ", 10);
            emit(crypte(get_next_line(0)));
	} else {
            if (nanosleep(&sleep_time, NULL) != 0) {
		my_putstr(decrypt(shot));
            } else
                write(2, "timeout\n", 8);
	}
        for (int i = 0; i < 9; i++)
            shot[i] = 0;
        player = (player == 1) ? 2 : 1;
    }
    return (0);
}
