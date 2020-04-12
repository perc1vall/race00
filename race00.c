
extern void mx_printchar(char c);
extern void mx_printstr(const char *s);
extern int mx_strlen(const char *s);

void race00(int map_length, int map_width, int one_y, int one_x){
	if ((map_length == 0 || map_width == 0)
		|| (map_length == 1 && map_width == 1)
		|| (one_y > map_length || one_x > map_width)) {
		
		return;	
	}
	map_width += 3;
	char map[map_length][map_width];
	for (int i = 0; i < map_length; i++){
		for (int j = 0; j < map_width+1; j++){
			if ((i % 2 == 0) && (j == 0 || j == map_width-2)){
				map[i][j] = '*';
			}
			else if ((i % 2 != 0) && (j == 0 || j == map_width-2)){
				map[i][j] = '+';
			}
			else {
				map[i][j] = '0';
			}
		map[i][map_width-1] = '\0';
		}
	}

	map[one_y][one_x+1] = '1';

	int y = 0;
	char limit[map_width];
	limit[map_width + 2] = '\0';
	while (y <= map_width) {
		if (y == 0)
			limit[0] = '<';
		if (y == map_width - 2)
			limit[map_width - 2] = '>';
		if (y == 1 || y == map_width - 3)
			limit[y] = '=';
		if (y > 1 && y < map_width - 3)
			limit[y] = '-';
		y++;
	}
	
	mx_printstr(limit);
	mx_printchar('\n');
	for (int i = 0; i < map_length; i++){
		mx_printstr(map[i]);
		mx_printchar('\n');
	}
	mx_printstr(limit);
	mx_printchar('\n');
}
