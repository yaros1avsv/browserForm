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
	VSTree->NodeDataSize = sizeof(VSTStruct); // ������ �� ���������
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenButtonClick(TObject *Sender)
{
	VSTree -> Clear(); // ������� ������
	sqlite3 *DB = NULL;
	if (sqlite3_open("history.sqlite", &DB)) {
		LabelStatus->Caption = "������ ��� �������� ����!";
	}
    sqlite3_stmt *pullStatement; // ������������ ��������
	const char *sqlSelect = "select * from urls"; // SQL-������ ������ �������
	int result = sqlite3_prepare_v2(DB, sqlSelect, -1, &pullStatement, NULL);
	if (result != SQLITE_OK) // ���� ������ ���������� �������
	{
		const char* errmsg = sqlite3_errmsg(DB); // ��������� ������ ������ SQL
		LabelStatus->Caption = errmsg; // ����� ������ �������
	}
	else
	{
		wchar_t* stringToShow;
		VSTree->BeginUpdate(); // ������ ��������� �������
		while (sqlite3_step(pullStatement) != SQLITE_DONE)
		{
			PVirtualNode entryNode = VSTree->AddChild(VSTree->RootNode);
			VSTStruct *nodeData = (VSTStruct*)VSTree->GetNodeData(entryNode);
			nodeData->id = sqlite3_column_int(pullStatement, 0);
			nodeData->url  = (wchar_t*)sqlite3_column_text16(pullStatement, 1);
			nodeData->title  = (wchar_t*)sqlite3_column_text16(pullStatement, 2);
			nodeData->visit_count = sqlite3_column_int(pullStatement, 3);
		}
		VSTree->EndUpdate(); // ��������� �������
	}
	sqlite3_finalize(pullStatement); // ������� ������
	sqlite3_close(DB); // ������������ ��
}
//---------------------------------------------------------------------------
void __fastcall TForm1::VSTreeGetText(TBaseVirtualTree *Sender, PVirtualNode Node, TColumnIndex Column,
          TVSTTextType TextType, UnicodeString &CellText)
{
    if(!Node) return;
	VSTStruct *nodeData = (VSTStruct*)Sender->GetNodeData(Node);
	switch(Column)
	{
		case 0: CellText = nodeData->id; break;
		case 1: CellText = nodeData->url; break;
		case 2: CellText = nodeData->title; break;
		case 3: CellText = nodeData->visit_count; break;
	}
}



