using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using XOProject.Properties;

namespace XOProject
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void frmMain_Paint(object sender, PaintEventArgs e)
        {
            
            Color White = Color.White;
            Pen Pen = new Pen(White);
            Pen.Width = 10;

            Pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            Pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            e.Graphics.DrawLine(Pen, 350, 75, 350, 525);
            e.Graphics.DrawLine(Pen, 500, 75, 500, 525);

            e.Graphics.DrawLine(Pen, 200, 225, 650, 225);
            e.Graphics.DrawLine(Pen, 200, 375, 650, 375);
            
            
        }

        enum enTurn
        { 
            Player1 = 1,
            Player2 = 2
        };

        enum enWinner
        {
            Player1 = 1,
            Player2 = 2,
            Draw = 3,
            GameInProgress = 4
        };

        struct stGameStatus
        {
            public enWinner Winner;
            public short PlayCount;
            public bool GameOver;

        };

        stGameStatus GameStatus;
        enTurn PlayerTurn = enTurn.Player1;

        public bool CheckValues (PictureBox pb1, PictureBox pb2, PictureBox pb3)
        {
            if (pb1.Tag.ToString() != "?" && pb1.Tag.ToString() == pb2.Tag.ToString() && pb1.Tag.ToString() == pb3.Tag.ToString())
            {
                pb1.BackColor = pb2.BackColor = pb3.BackColor = Color.Green;
                
                if (pb1.Tag.ToString() == "X")
                {
                    GameStatus.Winner = enWinner.Player1;
                }
                else
                {
                    GameStatus.Winner = enWinner.Player2;
                }
                GameStatus.GameOver = true;
                EndGame();
                return true;
            }
            GameStatus.GameOver = false;
            return false;
        }

        bool ThreePicsInRow()
        {
            return CheckValues(pictureBox1, pictureBox2, pictureBox3) 
                || CheckValues(pictureBox4, pictureBox5, pictureBox6)
                || CheckValues(pictureBox7, pictureBox8, pictureBox9);
        }

        bool ThreePicsInCol()
        {
            return CheckValues(pictureBox1, pictureBox4, pictureBox7)
                || CheckValues(pictureBox2, pictureBox5, pictureBox8)
                || CheckValues(pictureBox3, pictureBox6, pictureBox9);
        }

        bool ThreePicsInDiag()
        {
            return CheckValues(pictureBox1, pictureBox5, pictureBox9)
                || CheckValues(pictureBox3, pictureBox5, pictureBox7);
        }

        bool GameWon()
        {
            return ThreePicsInRow() || ThreePicsInCol() || ThreePicsInDiag();
        }

        void EndGame()
        {
            lblPlayer.Text = "Game Over";
            switch (GameStatus.Winner)
            {
                case enWinner.Player1:
                    lblWinner.Text = "Player 1";
                    break;

                case enWinner.Player2:
                    lblWinner.Text = "Player 2";
                    break;

                default:
                    lblWinner.Text = "Draw";
                    break;
            }

            MessageBox.Show("Game Over", "GameOver", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        void CheckWinner()
        {
            GameWon();
        }

        void ResetPictureBox (PictureBox pb)
        {
            pb.BackColor = Color.Black;
            pb.Tag = "?";
            pb.Image = Resources.questionMark;
        }

        void ResetGame()
        {
            lblPlayer.Text = "Player 1";
            PlayerTurn = enTurn.Player1;
            lblWinner.Text = "In Progress";

            ResetPictureBox(pictureBox1);
            ResetPictureBox (pictureBox2);
            ResetPictureBox (pictureBox3);
            ResetPictureBox (pictureBox4);
            ResetPictureBox (pictureBox5);
            ResetPictureBox (pictureBox6);
            ResetPictureBox (pictureBox7);
            ResetPictureBox (pictureBox8);
            ResetPictureBox (pictureBox9);

            GameStatus.Winner = enWinner.GameInProgress;
            GameStatus.PlayCount = 0;
            GameStatus.GameOver = false;
        }



        private void pictureBox_Click(object sender, EventArgs e)
        {
            if (GameStatus.GameOver == false)
            {

                if (((PictureBox)sender).Tag.ToString() == "?")
                {

                    if (PlayerTurn == enTurn.Player1)
                    {
                        ((PictureBox)sender).Image = Resources.X;
                        PlayerTurn = enTurn.Player2;
                        lblPlayer.Text = "Player 2";
                        ((PictureBox)sender).Tag = "X";

                    }
                    else
                    {
                        ((PictureBox)sender).Image = Resources.O;
                        PlayerTurn = enTurn.Player1;
                        lblPlayer.Text = "Player 1";
                        ((PictureBox)sender).Tag = "O";
                    }
                    GameStatus.PlayCount++;
                    CheckWinner();
                }
                else
                {
                    MessageBox.Show("Wrong Choice", "Wrong", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

                if (GameStatus.PlayCount == 9 && GameStatus.GameOver == false)
                {
                    GameStatus.GameOver = true;
                    GameStatus.Winner = enWinner.Draw;
                    EndGame();
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ResetGame();
        }

        private void button1_MouseEnter(object sender, EventArgs e)
        {
            Cursor = Cursors.Hand;
        }

        private void button1_MouseLeave(object sender, EventArgs e)
        {
            Cursor = Cursors.Default;
        }
    }
}
