//macro for table, decomposed into its parts
#macro Table (CENTRE_OF_X, BASE_Y, CENTRE_OF_Z, TEXTURE)
    //Legs of the table
    #local Leg_Left_Lower =
        cylinder{
            <CENTRE_OF_X - 3, BASE_Y - 4, CENTRE_OF_Z - 1.5>, <CENTRE_OF_X - 3, BASE_Y, CENTRE_OF_Z - 1.5>, 0.175
            open
        }
    #local Leg_Left_Upper =
        cylinder{
            <CENTRE_OF_X - 3, BASE_Y - 4, CENTRE_OF_Z + 1.5>, <CENTRE_OF_X - 3, BASE_Y, CENTRE_OF_Z + 1.5>, 0.175
            open
        }
    #local Leg_Right_Lower =
        cylinder{
            <CENTRE_OF_X + 3, BASE_Y - 4, CENTRE_OF_Z - 1.5>, <CENTRE_OF_X + 3, BASE_Y, CENTRE_OF_Z - 1.5>, 0.175
            open
        }
    #local Leg_Right_Upper =
        cylinder{
            <CENTRE_OF_X + 3, BASE_Y - 4, CENTRE_OF_Z + 1.5>, <CENTRE_OF_X + 3, BASE_Y, CENTRE_OF_Z + 1.5>, 0.175
            open
        }
    //putting it all together
    #union {
        object{
            box{
                <CENTRE_OF_X - 3, BASE_Y, CENTRE_OF_Z - 1.5>, <CENTRE_OF_X + 3, BASE_Y + 0.125, CENTRE_OF_Z + 1.5>
                texture{
                    TEXTURE
                    scale<1, 1, 1>
                    finish{
                        phong 1
                    }
                }
            }
        }
        object{Leg_Left_Lower texture{ TEXTURE scale<1, 5, 1> finish{ phong 1 }}}
        object{Leg_Left_Upper texture{ TEXTURE scale<1, 5, 1> finish{ phong 1 }}}
        object{Leg_Right_Lower texture{ TEXTURE scale<1, 5, 1> finish{ phong 1 }}}
        object{Leg_Right_Upper texture{ TEXTURE scale<1, 5, 1> finish{ phong 1 }}}
    }
#end //end of macro
