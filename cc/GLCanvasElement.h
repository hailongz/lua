//
//  GLCanvasElement.h
//  glelement
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#ifndef __glelement__GLCanvasElement__
#define __glelement__GLCanvasElement__

#include <iostream>

#include "GLElement.h"
#include "GLContext.h"

namespace cc {
    
    
    class GLCanvasElement : public GLElement{
        
    public:
        
        GLCanvasElement();
        
        virtual ~GLCanvasElement();
        
        DEC_CLASS
        
        virtual void begin(GLContext * context);
        
        virtual void end(GLContext * context);
        
        virtual void draw(GLContext * context);
      
        virtual Value value(const char * key);
        
        virtual void setValue(const char * key,Value value);
        
    
        GLfloat alpha;
        GLfloat scale;
        GLMatrix4 transform;
        bool hidden;
    };
    
}

#endif /* defined(__glelement__GLCanvasElement__) */
