//macro for a glass mug (idk if those exist)

#macro Mug()
    difference{
        union{
            cylinder{
                <0, -3, 0>, <0, 3, 0>, 3
                pigment {
                    color <1, 1, 1, 0.5>
                }
            }
        }
    }
