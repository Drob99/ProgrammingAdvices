using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyFirstWindowsFormsProject
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void btnShowPart1_Click(object sender, EventArgs e)
        {
            Form frm1 = new Form1();
            frm1.Show();
        }

        private void btnShowDialog_Click(object sender, EventArgs e)
        {
            Form frm1 = new Form1();
            frm1.ShowDialog();
        }

        private void btnMessageBoxForm_Click(object sender, EventArgs e)
        {
            Form frm1 = new frmMessageBox();
            frm1.ShowDialog();
        }

        private void btnCheckRadioGroup_Click(object sender, EventArgs e)
        {
            Form frm1 = new frmCheckRadioGroup();
            frm1.ShowDialog();
        }

        private void btnTextBox_Click(object sender, EventArgs e)
        {
            Form frmTextbox = new frmTextBox();
            frmTextbox.ShowDialog();
        }

        private void btnPictureBox_Click(object sender, EventArgs e)
        {
            Form frmPictureBox = new frmPictureBox();
            frmPictureBox.ShowDialog();
        }

        private void btnPictureBoxExercise_Click(object sender, EventArgs e)
        {
            Form frmPictureBoxExercise = new frmPictureBoxExercise();
            frmPictureBoxExercise.ShowDialog();
        }

        private void btnDrawing_Click(object sender, EventArgs e)
        {
            Form frmDrawing = new frmDrawing();
            frmDrawing.ShowDialog();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnMaskedTextBox_Click(object sender, EventArgs e)
        {
            Form frmMaskedTextBox = new frmMaskedText();
            frmMaskedTextBox.ShowDialog();
        }

        private void btnComboBox_Click(object sender, EventArgs e)
        {
            Form frmComboBox = new frmComboBox();
            frmComboBox.ShowDialog();
        }

        private void btnComboBoxExercise_Click(object sender, EventArgs e)
        {
            Form frmComboBoxExercise = new frmComboBoxExercise();
            frmComboBoxExercise.ShowDialog();
        }

        private void btnLinkLabel_Click(object sender, EventArgs e)
        {
            Form frmLinkLabel = new frmLinkLabel();
            frmLinkLabel.ShowDialog();
        }

        private void btnCheckedListBox_Click(object sender, EventArgs e)
        {
            Form frmCheckedListBox = new frmCheckedListBox();
            frmCheckedListBox.ShowDialog();
        }

        private void btnDateTimePicker_Click(object sender, EventArgs e)
        {
            Form frmDateTimePicker = new frmDateTimePicker();
            frmDateTimePicker.ShowDialog();
        }

        private void btnMonthCalendar_Click(object sender, EventArgs e)
        {
            Form frmMonthCalendar = new frmMonthCalendar();
            frmMonthCalendar.ShowDialog();
        }

        private void btnTimer_Click(object sender, EventArgs e)
        {
            Form frmTimer = new frmTimer();
            frmTimer.ShowDialog();
        }

        private void btnNotifyIcon_Click(object sender, EventArgs e)
        {
            Form frmNotifyIcon = new frmNotifyIcon();
            frmNotifyIcon.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form frmTreeView = new frmTreeView();
            frmTreeView.ShowDialog();
        }

        private void btnProgressBar_Click(object sender, EventArgs e)
        {
            Form frmProgressBar = new frmProgressBar();
            frmProgressBar.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form frmListView = new frmListView();
            frmListView.ShowDialog();
        }

        private void btnErrorProvider_Click(object sender, EventArgs e)
        {
            Form frmErrorProvider = new frmErrorProvider();
            frmErrorProvider.ShowDialog();
        }

        private void btnTrackBar_Click(object sender, EventArgs e)
        {
            Form frmTrackBar = new frmTrackBar();
            frmTrackBar.ShowDialog();
        }

        private void btnNumericUpDown_Click(object sender, EventArgs e)
        {
            Form frmNumericUpDown = new frmNumericUpDown();
            frmNumericUpDown.ShowDialog();
        }

        private void btnTabControl_Click(object sender, EventArgs e)
        {
            Form frmTabControl = new frmTabControl();
            frmTabControl.ShowDialog();
        }

        private void btnGroupBoxVsPanel_Click(object sender, EventArgs e)
        {
            Form frmGroupBoxVsPanel = new frmGroupBoxVsPanel();
            frmGroupBoxVsPanel.ShowDialog();
        }

        private void btnColorDialog_Click(object sender, EventArgs e)
        {
            Form frmColorDialog = new frmColorDialog();
            frmColorDialog.ShowDialog();
        }

        private void btnFontDialog_Click(object sender, EventArgs e)
        {
            Form frmFontDialog = new frmFontDialog();
            frmFontDialog.ShowDialog();
        }

        private void btnFileSaveDialog_Click(object sender, EventArgs e)
        {
            Form frmFileSaveDialog = new frmFileSaveDialog();
            frmFileSaveDialog.ShowDialog();
        }

        private void btnFileOpenDialog_Click(object sender, EventArgs e)
        {
            Form frmFileOpenDialog = new frmFileOpenDialog();
            frmFileOpenDialog.ShowDialog();
        }

        private void btnFolderBrowserDialog_Click(object sender, EventArgs e)
        {
            Form frmFolderBrowserDialog = new frmFolderBrowserDialog();
            frmFolderBrowserDialog.ShowDialog();
        }

        private void btnMDIContainer_Click(object sender, EventArgs e)
        {
            Form frmMDIContainer = new frmMDIContainer();
            frmMDIContainer.ShowDialog();
        }

        private void btnMenuStrip_Click(object sender, EventArgs e)
        {
            Form frmMenuStrip = new frmMenuStrip();
            frmMenuStrip.ShowDialog();
        }

        private void btnContextMenu_Click(object sender, EventArgs e)
        {
            Form frmContextMenu = new frmContextMenu();
            frmContextMenu.ShowDialog();
        }
    }
}
