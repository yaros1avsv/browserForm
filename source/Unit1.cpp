//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <string>
#include "sqlite3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	VSTree->NodeDataSize = sizeof(VSTStruct); // размер по структуре
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenButtonClick(TObject *Sender)
{
  VSTree -> Clear(); // очистка дерева
	sqlite3 *DB = NULL;
	sqlite3_stmt *pullStatement; // возвращаемое значение
	const char *sqlSelect = "select * from urls"; // SQL-запрос вывода таблицы
	int result = sqlite3_prepare_v2(DB, sqlSelect, -1, &pullStatement, NULL);
	if (result != SQLITE_OK) // если запрос закончилс€ ошибкой
	{
		const char* errmsg = sqlite3_errmsg(DB); // получение текста ошибки SQL
		LabelStatus->Caption = errmsg; // вывод ошибки запроса
	}
	else // если запрос завершилс€ успешно
	{
		wchar_t* stringToShow;
		LabelStatus -> Caption = "Ѕаза загружена";
		VSTree->BeginUpdate(); // запрет изменений таблицы
		while (sqlite3_step(pullStatement) != SQLITE_DONE)
		{
			PVirtualNode entryNode = VSTree->AddChild(VSTree->RootNode);
			VSTStruct *nodeData = (VSTStruct*)VSTree->GetNodeData(entryNode);
			nodeData->id = sqlite3_column_int(pullStatement, 0);
			nodeData->url  = (wchar_t*)sqlite3_column_text16(pullStatement, 1);
			nodeData->title  = (wchar_t*)sqlite3_column_text16(pullStatement, 2);
			nodeData->visit_count  = sqlite3_column_int(pullStatement, 3);
		}
		VSTree->EndUpdate(); // отрисовка таблицы
	}
	sqlite3_finalize(pullStatement); // очистка вывода
	sqlite3_close(DB); // освобождение Ѕƒ
}
//---------------------------------------------------------------------------



