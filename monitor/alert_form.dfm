object AlertForm: TAlertForm
  Left = 0
  Top = 0
  Caption = #25253#35686#31383#21475
  ClientHeight = 484
  ClientWidth = 509
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 509
    Height = 424
    Align = alClient
    Caption = #25253#35686#21015#34920
    TabOrder = 0
    object _alertList: TListView
      Left = 2
      Top = 15
      Width = 505
      Height = 407
      Align = alClient
      Checkboxes = True
      Columns = <
        item
          MaxWidth = 20
          MinWidth = 20
          Width = 20
        end
        item
          Alignment = taCenter
          AutoSize = True
          Caption = #31561#32423
          MaxWidth = 40
          MinWidth = 40
        end
        item
          Alignment = taCenter
          AutoSize = True
          Caption = 'IP'#22320#22336
          MaxWidth = 160
        end
        item
          AutoSize = True
          Caption = #25253#35686#21407#22240
        end>
      GridLines = True
      MultiSelect = True
      TabOrder = 0
      ViewStyle = vsReport
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 424
    Width = 509
    Height = 60
    Align = alBottom
    Caption = #25805#20316
    TabOrder = 1
    object _btnEmptySel: TButton
      Left = 3
      Top = 24
      Width = 75
      Height = 25
      Caption = #28165#31354#36873#20013#39033
      TabOrder = 0
      OnClick = _btnEmptySelClick
    end
    object _btnEmptyAll: TButton
      Left = 84
      Top = 24
      Width = 75
      Height = 25
      Caption = #28165#31354#20840#37096
      TabOrder = 1
      OnClick = _btnEmptyAllClick
    end
  end
end
