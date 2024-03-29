#ifndef COBJECTCOLLECTOR_H
#define COBJECTCOLLECTOR_H
#include "CObject.h"
#include <vector>
#include "template_singleton.h"
#include "CTextureManager.h"
///I add this into most headers because I was getting an
///error I have never gotten about NULL not being defined
#ifndef NULL
  #define NULL 0
#endif
///the type 'objectRef' is given to every object so that
///they can easily be tracked by the object collector.
typedef unsigned int objectRef;

namespace necropolis{
  class CObjectCollector{
  private:
  public:
    std::vector<CObject*> mObjectList;
    ~CObjectCollector();
    ///NewObject( CObject* a_objectPtr )
    ///adds an object to the list and returns it's reference.
    objectRef NewObject(CObject* a_objectPtr);
    objectRef NewObject(CObject& a_objectPtr);
    objectRef NewObject(CObject a_objectPtr);
    ///FreeObject( objectRef a_objectRef )
    ///removes an object from the list, freeing it in the process
    void FreeObject(objectRef a_objectRef);

    CObject* GetObjectByRef(objectRef oRef);
    void DrawAllObjects(SDL_Surface* screen);
  };
}
#endif

