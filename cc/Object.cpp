//
//  Object.cpp
//  lua
//
//  Created by zhang hailong on 14-6-19.
//  Copyright (c) 2014年 hailong.org. All rights reserved.
//

#include "Object.h"

#include "Log.h"

#include "Context.h"

namespace cc {
    
    static cc::Object * Object_alloc() { return new Object(); };
    
    cc::Class Object::clazz = {NULL,"Object",Object_alloc,sizeof(Object)};
    

    Object::Object():_retainCount(1){

    }
    
    Object::~Object(){
        
    }
    
    int Object::retainCount(){
        return _retainCount;
    }
    
    Object * Object::retain(){
        _retainCount ++;
        return this;
    }
    
    void Object::release(){
        
        if( --_retainCount == 0){
            delete this;
        }
    }
    
    Value Object::value(const char * key){
        
        if(strcmp(key, "className") == 0){
            return Value(clazz.name);
        }
        
        return Value(& Object::invoke);
    }
    
    void Object::setValue(const char * key,Value value){
        
    }
    
    Value Object::invoke(const char * key,InvokeArgs * args){
        if(strcmp(key, "isKindOfClass") == 0){
            const char * className = ValueToString(InvokeArgsValue(args, 0), NULL);
            if(className){
                Context * ctx = Context::current();
                if(ctx){
                    Class * clazz = ctx->getClass(className);
                    if(clazz){
                        return Value(isKindOfClass(clazz));
                    }
                    else {
                        Log("Not Found Class %s",className);
                    }
                }
            }
            return Value(false);
        }
        return Value();
    }
    
    bool Object::isKindOfClass(Class * ofClass){
        return ClassIsKindOf(getClass(), ofClass);
    }
    
    bool ClassIsKindOf(Class * clazz,Class * ofClass){
        
        while (clazz && ofClass && clazz != ofClass) {
            clazz = clazz->superClass;
        }
        
        return clazz != NULL;
    }
    
    Class * Object::getClass(){
        return & Object::clazz;
    }
}
