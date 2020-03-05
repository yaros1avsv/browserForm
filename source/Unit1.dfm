object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 386
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object NameL: TLabel
    Left = 240
    Top = 8
    Width = 163
    Height = 23
    Caption = 'BROWSER FORM'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object LabelStatus: TLabel
    Left = 11
    Top = 37
    Width = 3
    Height = 13
  end
  object OpenButton: TButton
    Left = 8
    Top = 328
    Width = 193
    Height = 57
    Caption = 'Open'
    TabOrder = 0
    OnClick = OpenButtonClick
  end
  object RemoveButton: TButton
    Left = 224
    Top = 328
    Width = 193
    Height = 57
    Caption = 'Remove string'
    TabOrder = 1
    OnClick = RemoveButtonClick
  end
  object ClearAllButton: TButton
    Left = 434
    Top = 328
    Width = 193
    Height = 57
    Caption = 'Clear all'
    TabOrder = 2
  end
  object VSTree: TVirtualStringTree
    Left = 8
    Top = 56
    Width = 619
    Height = 266
    Header.AutoSizeIndex = 0
    TabOrder = 3
    TreeOptions.SelectionOptions = [toFullRowSelect]
    OnGetText = VSTreeGetText
    Columns = <
      item
        Position = 0
        Text = 'URL'
      end
      item
        Position = 1
        Text = 'Title'
      end
      item
        Position = 2
        Text = 'Visited On'
      end
      item
        Position = 3
        Text = 'Visit Count'
      end>
  end
end
