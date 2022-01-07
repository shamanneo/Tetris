#pragma once

const INT BLOCK_WIDTH_COUNT = 14 ;
const INT BLOCK_HEIGHT_COUNT = 23 ;

const INT DEFAULT_ARRAY_SIZE = 9 ; 
const INT HERO_ARRAY_SIZE = 16 ; 

const INT BOARD_BOUND = 9 ;

const INT DEFAULT_VELOCITY = 200    ; 

enum class BlockId
{
    ID_VOID = 0,
    ID_LICKY = 30,
    ID_RICKY = 31,
    ID_CLEVELAND = 32,
    ID_PHODEISLAND = 33,
    ID_TEEWEE = 34,
    ID_SMASHBOY = 35,
    ID_HERO = 36
} ;

enum 
{
    BLOCK_ARRAY_SPACE_ON = 1,
    BLOCK_ARRAY_SPACE_OFF = 0
} ; 

enum 
{
    BLOCK_ARRAY_LEFT_POS = 0,
    BLOCK_ARRAY_MID_POS,
    BLOCK_ARRAY_RIGHT_POS 
} ; 