/**
 * @file Array_of_boxes.c
 * @author Bharath.G (bharath.g@ltts.com)
 * @brief Program to show the use of Array of structures, Dynamic memory allocation and pointers.
 * This example implements an array of boxes. Each box is a structure by itself. 
 * Each box has different properties like id - a non zero value, length, weight, breadth, height and color.
 * Function are written to create dynamic memory to hold these boxes into a array so that addtional operations can be performed.
 * 
 * @version 0.1
 * @date 2021-03-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @enum error_t
 *  @brief This enum is a definition of errors
 */
typedef enum error_t
{
    SUCCESS = 0,    /**< Success */
    MEMORY_FAILURE, /**< Memory Allocation failure Full */
    ARRAY_FULL,     /**< Array is full */
    NULL_PTR,       /**< Error Code for Failure */

} error_t;

/** @enum color_t
 *  @brief This enum is a definition of colours
 */
typedef enum color_t
{
    RED = 0xFF, /**< Colour Code for RED */
    BLUE,       /**< Colour Code for BLUE */
    GREEN       /**< Colour Code for GREEN */
} color_t;

/** @struct box_t
 *  @brief This structure is a definition of box and its attributes
 */
typedef struct box_t
{
    uint8_t id;    /**< ID of the Box */
    float length;  /**< Length of the Box */
    float breadth; /**< Breadth of the Box */
    float height;  /**< Height of the Box */
    float weight;  /**< Weight of the Box */
    color_t color; /**< Colour of the Box */
} box_t;

/**
 * @brief Creates an Array of box dynamically
 * @param[in] box_ptr   Pointer to the array of Boxes
 * @param[in] number_of_boxes Number of Boxes in Array
 * @return Pointer to the newly created Box Array
 */
box_t *create_array_of_box(const size_t number_of_boxes)
{
    return calloc(number_of_boxes, sizeof(box_t));
}

/**
 * @brief Adds a box to the end of the current array where ID is NULL
 * @param[in] box_ptr Pointer to the array of Boxes
 * @param[in] array_size Size of the array
 * @param[in] new_box New box to be added at the end of the array
 * @return Success if the New box is added. Error code otherwise
 */
error_t add_box_at_end(box_t *box_ptr, const size_t array_size, const box_t *new_box)
{
    if (NULL == box_ptr)
    {
        return NULL_PTR;
    }
    for (int index = 0; index < array_size; index++)
    {
        if (0 != (box_ptr + index)->id)
        {
            continue;
        }
        else
        {
            memcpy((box_ptr + index), new_box, sizeof(box_t));
            return SUCCESS;
        }
    }
    return ARRAY_FULL;
}

/**
 * @brief Displays attributes of all boxes in the passed array.
 * @param[in] Box_array   Pointer to the array of Boxes
 * @param[in] array_size    Size of the array
 * @return Success if passed array is not NULL
 */
error_t display_all(const box_t *Box_array, const size_t array_size)
{
    if (NULL == Box_array)
    {
        return NULL_PTR;
    }
    for (int index = 0; index < array_size && (0 != (Box_array + index)->id); index++)
    {
        printf("ID = %d \nLength = %f  \nBreadth = %f \nHeight=%f \nWeight = %f \n",
               (Box_array + index)->id,
               (Box_array + index)->length,
               (Box_array + index)->breadth,
               (Box_array + index)->height,
               (Box_array + index)->weight);
        switch ((Box_array + index)->color)
        {
        case RED:
            printf("Color = RED\n\n");
            break;
        case BLUE:
            printf("Color = BLUE\n\n");
            break;
        case GREEN:
            printf("Color = BLUE\n\n");
            break;
        default:
            printf("Color = DEFAULT\n\n");
        }
    }
    return SUCCESS;
}

/**
 * Code to test the above functions
 */
size_t ARRAY_SIZE = 3;

// If not assigned with NULL, it becomes a wild pointer
box_t *box_ptr = NULL;

// Initialize two box variables
box_t box1 = {1, 10.2, 10.3, 22.566, 23.7777, RED};
box_t box2 = {2, .breadth = 99.99, .color = GREEN};
box_t box3 = {2, .breadth = 99.99, .color = GREEN};

int main()
{
    // Allocate memory to hold the boxes
    box_ptr = create_array_of_box(ARRAY_SIZE);

    /** Add a box to the array */
    add_box_at_end(box_ptr, ARRAY_SIZE, &box1);
    add_box_at_end(box_ptr, ARRAY_SIZE, &box2);

    /** Display all the added boxes */
    display_all(box_ptr, ARRAY_SIZE);

    // release the dynamically allocated memory
    //free(box_ptr);
    box_ptr = NULL;
}