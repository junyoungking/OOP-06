#pragma once
#include "header.h"
#include "NDatabase.h"
#include "ADatabase.h"
#include "CDatabase.h"


	class Face
	{
	public:
		Face(void);
		~Face(void);

		void Start();
		void Run();
		void makeadb();
		void makendb();
		void makecdb();
	private:
		ADatabase* adb = new ADatabase();
		NDatabase* ndb = new NDatabase();
		CDatabase* cdb = new CDatabase();

	};

