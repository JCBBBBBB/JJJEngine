#pragma once

#define SINGLETONE(classname)							\
public:													\
	static classname* GetInstance()						\
	{													\
		static classname instance;						\
		return &instance;								\
	}													\
private:												\
	classname() = default;

#define GET_SINGLETONE(classname) classname->GetInstance();