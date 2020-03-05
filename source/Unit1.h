//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "VirtualTrees.hpp"

// переменная структуры VST
struct VSTStruct
{
	int id;
	UnicodeString url;
	UnicodeString title;
	int visit_count;
};

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *OpenButton;
	TButton *RemoveButton;
	TButton *ClearAllButton;
	TVirtualStringTree *VSTree;
	TLabel *NameL;
	TLabel *LabelStatus;
	void __fastcall OpenButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
