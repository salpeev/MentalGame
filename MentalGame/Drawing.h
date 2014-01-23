//
//  Drawing.h
//  MentalGame
//
//  Created by Sergey Alpeev on 23.01.14.
//  Copyright (c) 2014 Sergey Alpeev. All rights reserved.
//

#include "GLSLDrawRequest.h"



namespace Renderer {
    
    class Drawing {
    public:
        Drawing();
        Drawing(GLSLDrawRequest *pDrawRequest);
        Drawing(const Drawing &rDrawing) = delete;
        virtual ~Drawing();
        
        virtual void Draw() const = 0;
        
    protected:
        void SetAttributeInitializer(GLSLAttributeInitializer *pAttributeInitializer);
        void SetUniformInitializer(GLSLUniformInitializer *pUniformInitializer);
        
        GLSLAttributeInitializer *GetAttributeInitializer() const;
        GLSLUniformInitializer *GetUniformInitializer() const;
        
    private:
        GLSLDrawRequest *m_drawRequest;
        GLSLAttributeInitializer *m_attributeInitializer;
        GLSLUniformInitializer *m_uniformInitializer;
    };
}
