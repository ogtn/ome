////////////////////////////////////////////////////////////////////////
// SuperPointer.hpp
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef HPP_SUPERPOINTER
#define HPP_SUPERPOINTER

namespace OpenMouleEngine
{
    class SuperPointerBase
    {
    protected:
        SuperPointerBase();
        SuperPointerBase(void *p);
        SuperPointerBase(const SuperPointerBase &sp);

        bool isValid();

        SuperPointerBase &operator =(void *p);
        SuperPointerBase &operator =(const SuperPointerBase &sp);

    protected:
        void *ptr;
        int *refCount;
    };


    template <typename T>
    class SuperPointer: public SuperPointerBase
    {
    public:
        SuperPointer();
        SuperPointer(T *p);
        SuperPointer(const SuperPointer &sp);

        template <typename U>
        SuperPointer(const SuperPointer<U> &sp);
        ~SuperPointer();

        bool operator ==(const SuperPointer &sp);
        bool operator !=(const SuperPointer &sp);

        template <typename U>
        bool operator ==(const SuperPointer<U> &sp);

        template <typename U>
        bool operator !=(const SuperPointer<U> &sp);

        SuperPointer &operator =(T *p);
        SuperPointer &operator =(const SuperPointer &sp);

        template <typename U>
        SuperPointer<T> &operator =(U *p);

        template <typename U>
        SuperPointer<T> &operator =(SuperPointer<U> &sp);

        T *operator ->();
        T *getPtr() const;

    private:
        void reset();
        void operator *();
        void operator &();
    };

#include "SuperPointer.inl"

} // namespace

#endif // HPP_SUPERPOINTER


/*
template <class T>
class InternalCounter
{
  protected:
    InternalCounter() : m_refCount(new int(1))
    {
      std::cout << "Nouveau compteur" << std::endl;
    }
    
    void copy(T *ptr)
    {
      std::cout << "Le compteur s'incrémente!" << std::endl;
      ptr = ptr;
      (*m_refCount)++;
    }
    
    void release(T *ptr)
    {
      std::cout << "Le compteur se decrémente!" << std::endl;
      (*m_refCount)--;
      
      if(*m_refCount == 0)
      {
	std::cout << "Suppression du compteur et de la ressource" << std::endl;
	delete m_refCount;
	delete ptr;
      }
    }
    
    void set(InternalCounter &cpt)
    {
      m_refCount = cpt.m_refCount;
    }
    
    int *m_refCount;
};


template <class T>
class ResourceCounter
{
  protected:
    ResourceCounter()
    {
    }
    
    void copy(T *ptr)
    {
      if(ptr)
	ptr->addRef();
    }
    
    void release(T *ptr)
    {
      if(ptr)
	ptr->release();
    }
    
    void set(ResourceCounter &cpt)
    {
      cpt = cpt;
    }
};


template <class T, template <class> class RefCounter = InternalCounter>
class SuperPointer : public RefCounter<T>
{
  public:
    SuperPointer() : m_ptr(NULL)
    {
    }
    
    SuperPointer(T *ptr) : m_ptr(ptr)
    {
    }
    
    SuperPointer(SuperPointer &sp) : RefCounter<T>(sp), m_ptr(sp.m_ptr)
    {
      sp.copy();
    }
    
    ~SuperPointer()
    {
      release(m_ptr);
    }
    
    SuperPointer &operator=(SuperPointer &sp)
    {
      if(sp.m_ptr != m_ptr)
      {
	release(m_ptr);
	sp.copy(sp.m_ptr);
	m_ptr = sp.m_ptr;
	set(sp);
      }
      
      return *this;
    }
    
  private:
    T *m_ptr;
};


class A
{
  public:
    A() : m_refCount(1)
    {
      std::cout << "Création de A" << std::endl;
    }
    
    ~A()
    {
      std::cout << "Suppression de A" << std::endl;
    }
    
    void addRef()
    {
      std::cout << "Incrementation du compteur de ref de A" << std::endl;
      m_refCount++;
    }
    
    void release()
    {
      std::cout << "Decrementation du compteur de ref de A" << std::endl;
      m_refCount--;
      
      if(m_refCount == 0)
      {
	std::cout << "Suppression de " << this << " dans le ResourceManager" << std::endl;
	delete this;
      }
    }
    
  private:
    int m_refCount;
};


int main(void)
{
  A *a = new A;
  SuperPointer<A, ResourceCounter> sma(a);
  SuperPointer<A, ResourceCounter> smb;
  std::cout << "ici" << std::endl;
  smb = sma;
  std::cout << "là" << std::endl;
  
  return 0;
}
*/