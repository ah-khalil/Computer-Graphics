#include "textures.inc"

//macro for a room
#macro Room(ROOM_MID_X, ROOM_BASE, ROOM_MID_Z, PIGMENT)
    #declare Window_Glass =
        texture{
            pigment{
                rgbf<0.98, 0.98, 0.98, 0.8>
            }
            finish{
                diffuse .1
                reflection .2
                specular 0.8
                phong 1
            }
        }
    #local TILE =
        texture{
            pigment{
                PIGMENT
            }
            finish {
                diffuse 0.3
                specular 0.8
            }
        } // end of texture
    
    #local Window =
        union{
            //Window Glass
            box{
                <ROOM_MID_X + 7.0, ROOM_BASE + 9.00, ROOM_MID_Z - 15>, <ROOM_MID_X + 9.0, ROOM_BASE + 11.25, ROOM_MID_Z - 15.25>
                texture{
                    Window_Glass
                }
            }
            box{
                <ROOM_MID_X + 4.5, ROOM_BASE + 9.00, ROOM_MID_Z - 15>, <ROOM_MID_X + 6.5, ROOM_BASE + 11.25, ROOM_MID_Z - 15.25>
                texture{
                    Window_Glass
                }
            }
            box{
                <ROOM_MID_X + 4.5, ROOM_BASE + 6.5, ROOM_MID_Z - 15>, <ROOM_MID_X + 6.5, ROOM_BASE + 8.5, ROOM_MID_Z - 15.25>
                texture{
                    Window_Glass
                }
            }
            box{
                <ROOM_MID_X + 7.0, ROOM_BASE + 6.5, ROOM_MID_Z - 15>, <ROOM_MID_X + 9.0, ROOM_BASE + 8.5, ROOM_MID_Z - 15.25>
                texture{
                    Window_Glass
                }
            }
            //End glass              
            
            //Window Frames            
            box{ //Mid Horizontal Piece
                <ROOM_MID_X + 4.0, ROOM_BASE + 8.5, ROOM_MID_Z - 14.75>, <ROOM_MID_X + 9.5, ROOM_BASE + 9.0, ROOM_MID_Z - 15.25>
                texture{
                    pigment{
                        color White
                    }
                }
            }
            box{ //Top Horizontal Piece
                <ROOM_MID_X + 4.0, ROOM_BASE + 11.55, ROOM_MID_Z - 14.75>, <ROOM_MID_X + 9.5, ROOM_BASE + 11.25, ROOM_MID_Z - 15.25>
                texture{
                    pigment{
                        color White
                    }
                }
            }
            box{ //Bottom Horizontal Piece
                <ROOM_MID_X + 4.0, ROOM_BASE + 6.0, ROOM_MID_Z - 14.75>, <ROOM_MID_X + 9.5, ROOM_BASE + 6.5, ROOM_MID_Z - 15.25>
                texture{
                    pigment{
                        color White
                    }
                }
            }
            box{ //Mid Vertical Piece
                <ROOM_MID_X + 7.0, ROOM_BASE + 11.75, ROOM_MID_Z - 14.75>, <ROOM_MID_X + 6.5, ROOM_BASE + 6, ROOM_MID_Z - 15.25>
                texture{
                    pigment{
                        color White
                    }
                }
            }
            box{ //Left Vertical Piece (From inside)
                <ROOM_MID_X + 4.0, ROOM_BASE + 11.75, ROOM_MID_Z - 14.75>, <ROOM_MID_X + 4.5, ROOM_BASE + 6, ROOM_MID_Z - 15.25>
                texture{
                    pigment{
                        color White
                    }
                }
            }
            box{ //Right Vertical Piece (From inside)
                <ROOM_MID_X + 9.5, ROOM_BASE + 11.75, ROOM_MID_Z - 14.75>, <ROOM_MID_X + 9, ROOM_BASE + 6, ROOM_MID_Z - 15.25>
                texture{
                    pigment{
                        color White
                    }
                }
            }
            //End frames
        }
    union{
        difference{
            box{
                <ROOM_MID_X - 15, ROOM_BASE, ROOM_MID_Z - 15>, <ROOM_MID_X + 15, ROOM_BASE + 15, ROOM_MID_Z + 15>
                texture{
                    TILE
                }
            }
            object{
                cylinder{
                    <0, 0, 0>, <0, 1, 0>, 0.68
                    rotate<270, 0, 0>
                    translate<0, 5.75, 25.5>
                }
            }
            object{
                Window
            }
            object{
                Window
                translate<-13, 0, 0>
            }            
        } 
    }
#end //end of macro
