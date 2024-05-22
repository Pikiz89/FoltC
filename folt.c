#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "folt.h"


bool are_positions_equals(position_t *p_pos, position_t *p_pos2){
/*
* The are_positions_equals function returns true if the position_t variables references by 
* p_pos and p_pos2 are equal field by field; false otherwise (even in case of invalid pointers).
*/
    if (p_pos == NULL || p_pos2 == NULL){
        return false;
    }
    else if (((p_pos)->x == (p_pos2)->x)&&((p_pos)->y == (p_pos2)->y)){
        return true;
    }
    return false;
}
void set_position(unsigned int x, unsigned int y, position_t * p_pos){
    /*
* The set_position function modifies the fields x and y of the position_t 
* referenced by p_pos, according to the values of the parameters x and y.
* The function displays an error message and ends the program in case of 
* invalid arguments.
*/
    if (p_pos ==NULL){
        fprintf(stderr, "erreur");
        exit(EXIT_FAILURE);
    }
    (p_pos)->x = x;
    (p_pos)->y = y;
}


bool are_directions_equals(direction_t *p_dir, direction_t *p_dir2){
/*
* The are_directions_equals function returns true if the direction_t variables referenced
* by p_dir and p_dir2 are equal field by field; false otherwise (including the case of invalid
* pointers)
*/
    if (p_dir == NULL || p_dir2 == NULL){
        return false;
    }

    if((p_dir->deltax == p_dir2->deltax) && (p_dir->deltay == p_dir2->deltay)){
        return true;
    }
    return false;
}

void translate(position_t *p_position, direction_t *p_dir, position_t *p_newposition) {
/*
* The translate function computes the position resulting from the translation
* of the position_t referenced by p_position by the direction_t referenced by p_dir
* and stores the result in the position_t referenced by p_newposition.
* The function displays an error message and ends the program in case of 
* invalid arguments to the function, if the translation would result in an invalid position
* (with negative coordinates), or if the position resulting from the translation cannot be 
* represented by the position_t type (i.e. x and/or y are too large).
*/
    if (p_position == NULL || p_dir == NULL || p_newposition == NULL) {
        hard_treat_error("Error: NULL pointer argument.");
        exit(EXIT_FAILURE);
    }

    long new_x = (long)p_position->x + p_dir->deltax;
    long new_y = (long)p_position->y + p_dir->deltay;

    if (new_x > UINT_MAX || new_x < 0 || new_y > UINT_MAX || new_y < 0) {
        hard_treat_error("Error: Position overflow/underflow.");
        exit(EXIT_FAILURE);
    }

    p_newposition->x = (unsigned int)new_x;
    p_newposition->y = (unsigned int)new_y;
}
int main(void){
    position_t p = (position_t) { 15, 2 };
    position_t p2 = (position_t) { 10, 4 };
    position_t p3;
    position_t p4;
    position_t p5;
    direction_t d = (direction_t) { 5, -2 };
    direction_t d2 = (direction_t) { -5, 2 };
    direction_t d3 = (direction_t) { 5, -2 };
    set_position(15, 2, &(p3));
    translate(&(p2), &(d), &(p4));
    translate(&(p), &(d2), &(p5));
    print_position(&(p));
    print_position(&(p2));
    print_position(&(p3));
    print_position(&(p4));
    print_position(&(p5));
    print_direction(&(d));
    print_direction(&(d2));
    print_direction(&(d3));
    if(!are_positions_equals(&(p),&(p2))){
        printf("p and p2 are different.\n");
    }
    if(are_positions_equals(&(p),&(p3))){
        printf("p and p3 are equal.\n");
    }
    if(are_positions_equals(&(p),&(p4))){
        printf("p and p4 are equal.\n");
    }
    if(are_positions_equals(&(p2),&(p5))){
        printf("p2 and p5 are equal.\n");
    }
    if(!are_directions_equals(&(d),&(d2))){
        printf("d and d2 are different.\n");
    }
    if(are_directions_equals(&(d),&(d3))){
        printf("d and d3 are equal.\n");
    }
    return EXIT_SUCCESS;
}
