import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.net.*;
import java.io.*;
import java.util.Objects;

public class server extends JFrame
{
    ServerSocket Server;
    Socket socket;
    BufferedReader br;
    PrintWriter out;
    private final JLabel heading=new JLabel();
    private final JTextArea messageArea=new JTextArea();
    private final JTextField messageInput=new JTextField();
    private final Font font=new Font("Roboto",Font.PLAIN,35);
    public server()
    {
        try
        {
            Server=new ServerSocket(7777);
            System.out.println("server is ready to accept connection\n");
            System.out.println("waiting...");
            socket=Server.accept();
            br=new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintWriter(socket.getOutputStream());

            createGUI();
            handleEvent();

            startReading();
            //startwriting();

        }
        catch (Exception e)
        {
            throw new RuntimeException(e);
        }

    }
    private void handleEvent()
    {
        messageInput.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e)
            {

            }

            @Override
            public void keyPressed(KeyEvent e)
            {

            }

            @Override
            public void keyReleased(KeyEvent e)
            {
                System.out.println("key released"+e.getKeyCode());
                if(e.getKeyCode()==10)
                {
                    String contentToSend=messageInput.getText();
                    messageArea.append("Sachin :- "+contentToSend+"\n");
                    out.println(contentToSend);
                    out.flush();
                    messageInput.getText();
                    messageInput.requestFocus();
                }

            }
        });
    }

    private void createGUI()
    {
        this.setTitle("SamChat---s");
        this.setSize(500,500);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        heading.setFont(font);
        messageArea.setFont(font);
        messageInput.setFont(font);

        heading.setIcon(new ImageIcon("sachin crop black500.png"));
        try {
            Image img = ImageIO.read(Objects.requireNonNull(getClass().getResource("sam.png")));
            heading.setIcon(new ImageIcon(img));
        } catch (IOException e) {
            System.err.println("Error loading icon: " + e.getMessage());
        }

        heading.setHorizontalTextPosition(SwingConstants.CENTER);
        heading.setVerticalTextPosition(SwingConstants.BOTTOM);
        heading.setHorizontalAlignment(SwingConstants.CENTER);
        heading.setBorder(BorderFactory.createEmptyBorder(20,20,20,20));

        messageArea.setEnabled(false);
        messageInput.setHorizontalAlignment(SwingConstants.CENTER);

        this.setLayout(new BorderLayout());

        this.add(heading,BorderLayout.NORTH);
        JScrollPane jScrollPane=new JScrollPane(messageArea);
        this.add(jScrollPane,BorderLayout.CENTER);
        this.add(messageInput,BorderLayout.SOUTH);

        this.setVisible(true);

    }

    public void startReading()
    {
        Runnable r1;
        r1 = ()->
        {
            System.out.println("reader reading the massage....\n");
            try
            {
                while (true)
                {
                    String msg = br.readLine();
                    if (msg.equalsIgnoreCase("exit"))
                    {
                        System.out.println("client want to exit\n\n");
                        JOptionPane.showMessageDialog(this,"user terminated the chat");
                        messageInput.setEnabled(false);
                        socket.close();
                        break;
                    }
                    //System.out.println("user :- " + msg);
                    messageArea.append("Ramesh :- " + msg+"\n");
                }

            }
            catch (Exception e)
            {
                //throw new RuntimeException(e);
                System.out.println("\n\nconnection closed\n\n");
            }

        };
        new Thread(r1).start();
    }

    public void startwriting()
    {
        Runnable r2;
        r2 = ()->
        {
            System.out.println("writer started writing...\n");
            try
            {
                while (!socket.isClosed())
                {

                    BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));
                    String content = br1.readLine();
                    out.println(content);
                    out.flush();
                    if(content.equals("exit"))
                    {
                        socket.close();
                        break;
                    }

                }
            }
            catch (Exception e)
            {
                //throw new RuntimeException(e);
                System.out.println("\n\n connection closed\n\n");
            }
        };
        new Thread(r2).start();
    }

    public static void main(String[] args)
    {
        System.out.println("this is server...going to start server\n");
        new server();
    }
}
