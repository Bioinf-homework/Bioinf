# coding=utf-8
import wx

from Lib import *

# ----------------------------------------------------------------------------

TitleTexts = [u"K操作",
              u"Fasta算法",
              u"编辑距离",
              u"NW&SW算法",
              u"ID3决策树"
              ]


class TestCB(wx.Choicebook):
    def __init__(self, parent):
        wx.Choicebook.__init__(self, parent, wx.ID_ANY)

        # Now make a bunch of panels for the choice book
        count = 1
        for txt in TitleTexts:
            if count == 1:
                win = K.Panel1(self)
            elif count == 2:
                win = Fasta.Panel2(self)
            elif count == 3:
                win = Editd.Panel3(self)
            elif count == 4:
                win = NWSW.Panel3(self)
            else:
                win = DT.Panel4(self)
            count += 1

            self.AddPage(win, txt)


########################################################################
class DemoFrame(wx.Frame):
    """
    Frame that holds all other widgets
    """

    # ----------------------------------------------------------------------
    def __init__(self):
        """Constructor"""
        wx.Frame.__init__(self, None, wx.ID_ANY,
                          u" 生物信息学I 实验",
                          size=(650, 640))

        panel = wx.Panel(self)

        notebook = TestCB(panel)
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.Add(notebook, 1, wx.ALL | wx.EXPAND, 5)
        panel.SetSizer(sizer)
        self.Layout()

        self.Show()


# ----------------------------------------------------------------------
if __name__ == "__main__":
    app = wx.PySimpleApp()
    frame = DemoFrame()
    app.MainLoop()
