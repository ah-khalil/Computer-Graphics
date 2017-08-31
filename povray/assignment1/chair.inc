//macro for a chair
#macro Chair(CH_Y, TEXTURE)
    union{
        object{
            Table(0, CH_Y, 0, TEXTURE)
            scale<0.25, 0.75, 0.5>
        }
        box{
            <-3 * 0.25, CH_Y * 0.75, -1.5 * 0.5>, <3 * 0.25, CH_Y + 2, -1.5 * 0.5 * 0.75>
            texture{
                TEXTURE
                scale<1, 1, 1>
                finish{
                    phong 1
                }
            }
        }
    }
#end //end of macro
