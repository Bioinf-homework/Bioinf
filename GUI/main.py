# coding=utf-8
import  wx

import Panel1
import Panel2
import Panel3
#----------------------------------------------------------------------------

TitleTexts = [ u"K操作",
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
                win = Panel1.Panel1(self)
            elif count == 2:
                win = Panel2.Panel2(self)
            elif count == 3 or count == 4:
                win = Panel3.Panel3(self)
            else:
                win = wx.Panel(self)
                st = wx.StaticText(win, -1, "Page: %d" % count, (10,10))
            count += 1
            
            self.AddPage(win, txt)

        # self.Bind(wx.EVT_CHOICEBOOK_PAGE_CHANGED, self.OnPageChanged)
        # self.Bind(wx.EVT_CHOICEBOOK_PAGE_CHANGING, self.OnPageChanging)


    def OnPageChanged(self, event):
        old = event.GetOldSelection()
        new = event.GetSelection()
        sel = self.GetSelection()
        event.Skip()

    def OnPageChanging(self, event):
        old = event.GetOldSelection()
        new = event.GetSelection()
        sel = self.GetSelection()
        event.Skip()


########################################################################
class DemoFrame(wx.Frame):
    """
    Frame that holds all other widgets
    """

    #----------------------------------------------------------------------
    def __init__(self):
        """Constructor"""        
        wx.Frame.__init__(self, None, wx.ID_ANY, 
                          u" 生物信息学I 实验",
                          size=(800,600))

        panel = wx.Panel(self)
        
        notebook = TestCB(panel)
        sizer = wx.BoxSizer(wx.VERTICAL)
        sizer.Add(notebook, 1, wx.ALL|wx.EXPAND, 5)
        panel.SetSizer(sizer)
        self.Layout()
        
        self.Show()
        
#----------------------------------------------------------------------
if __name__ == "__main__":
    app = wx.PySimpleApp()
    frame = DemoFrame()
    app.MainLoop()
    