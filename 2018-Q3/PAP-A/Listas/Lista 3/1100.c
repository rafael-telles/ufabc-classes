#include <stdlib.h>
#include <stdio.h>

typedef struct state_s {
	int x, y;
	int steps;
} state_t;

int state_is_valid(state_t* state) {
	return state->x >= 0 && state->x < 8 && state->y >= 0 && state->y < 8;
}

int state_equals(state_t* state1, state_t* state2) {
	return state1->x == state2->x && state1->y == state2->y;
}

state_t* state_copy(state_t* state) {
	state_t* copy = (state_t*) malloc(sizeof(state_t));
	copy->x = state->x;
	copy->y = state->y;

	return copy;
}

state_t* state_move(state_t* state, int dx, int dy) {
	state_t* new_state = state_copy(state);

	new_state->x += dx;
	new_state->y += dy;
	new_state->steps = state->steps + 1;

	if (!state_is_valid(new_state)) {
		free(new_state);
		new_state = NULL;
	}

	return new_state;
}

typedef struct state_list_s {
	state_t** states;
	int read_cursor;
	int write_cursor;
} state_list_t;

state_list_t* state_list_create(int cap) {
	state_list_t* ret = (state_list_t*) malloc(sizeof(state_list_t));
	ret->states = (state_t**) malloc(sizeof(state_t*) * cap);
	ret->read_cursor = 0;
	ret->write_cursor = 0;

	return ret;
}

int state_list_free(state_list_t* state_list) {
	free(state_list->states);
	free(state_list);
}

int state_list_append(state_list_t* state_list, state_t* state) {
	state_list->states[state_list->write_cursor++] = state;
}

state_t* state_list_read_next(state_list_t* state_list) {
	int i = state_list->read_cursor++;
	if (i >= state_list->write_cursor) {
		return NULL;
	}
	state_t* ret = state_list->states[i];
	return ret;
}

int state_expand(state_list_t* state_list, state_t* state) {
	state_t* s1 = state_move(state, -2, -1);
	if (s1 != NULL) {
		state_list_append(state_list, s1);
	}
	state_t* s2 = state_move(state, 2, -1);
	if (s2 != NULL) {
		state_list_append(state_list, s2);
	}
	state_t* s3 = state_move(state, -2, 1);
	if (s3 != NULL) {
		state_list_append(state_list, s3);
	}
	state_t* s4 = state_move(state, 2, 1);
	if (s4 != NULL) {
		state_list_append(state_list, s4);
	}
	state_t* s5 = state_move(state, -1, -2);
	if (s5 != NULL) {
		state_list_append(state_list, s5);
	}
	state_t* s6 = state_move(state, -1, 2);
	if (s6 != NULL) {
		state_list_append(state_list, s6);
	}
	state_t* s7 = state_move(state, 1, -2);
	if (s7 != NULL) {
		state_list_append(state_list, s7);
	}
	state_t* s8 = state_move(state, 1, 2);
	if (s8 != NULL) {
		state_list_append(state_list, s8);
	}
}

int search(state_list_t* state_list, state_t* target) {
	while(1) {
		state_t* current_state = state_list_read_next(state_list);
		if (current_state == NULL) {
			return -1;
		}
		if (state_equals(current_state, target)) {
			return current_state->steps;
		}

		state_expand(state_list, current_state);
	}
}

int main() {
	char cy1, cy2;
	int x1, x2, y1, y2;
	while (scanf("%c%d %c%d\n", &cy1, &x1, &cy2, &x2) != EOF) {
		x1--;
		x2--;
		y1 = cy1 - 'a';
		y2 = cy2 - 'a';

		state_t s0;
		s0.x = x1;
		s0.y = y1;
		s0.steps = 0;

		state_list_t* state_list = state_list_create(1000);
		state_list_append(state_list, &s0);

		state_t sf;
		sf.x = x2;
		sf.y = y2;
		int steps = search(state_list, &sf);

		printf("To get from %c%d to %c%d takes %d knight moves.\n", cy1, x1+1, cy2, x2+1, steps);
	}

	return 0;
}