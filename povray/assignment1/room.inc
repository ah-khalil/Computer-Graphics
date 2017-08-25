//macro for a room
#macro Room(ROOM_MID_X, ROOM_BASE, ROOM_MID_Z, TEXTURE)
    #local WindowPane =
        box{
            <ROOM_MID_X + 10, ROOM_BASE + 9, 1>, <ROOM_MID_X + 12, ROOM_BASE + 11, -1>
        }
    difference{
        box{
            <ROOM_MID_X - 10, ROOM_BASE, ROOM_MID_Z - 10>, <ROOM_MID_X + 10, ROOM_BASE + 20, ROOM_MID_Z + 10>
            texture{
                TEXTURE
                scale<1, 1, 1>
                finish{
                    phong 1
                }
            }
        }
        object{WindowPane}
    }
#end //end of macro
