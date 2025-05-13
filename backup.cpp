class pessanger : public Destination
{
    int des_x[2];
    int des_y[2];
    int per1[2];
    int per2[2];
    bool pickup[2];
    bool drop[2];
    bool checker = false;
    bool overlap = true;

public:
    pessanger()
    {
        if (!checker)
        {
            generate();
            for (int i = 0; i < 2; i++)
            {
                do
                {
                    des_x[i] = 200 + rand() % 350;
                    des_y[i] = 200 + rand() % 350;
                } while ((des_x[i] >= 150 && des_x[i] <= 300 && des_y[i] >= 100 && des_y[i] <= 280) ||
                         (des_x[i] >= 150 && des_x[i] <= 300 && des_y[i] >= 470 && des_y[i] <= 650) ||
                         (des_x[i] >= 650 && des_x[i] <= 800 && des_y[i] >= 470 && des_y[i] <= 650) ||
                         (des_x[i] >= 650 && des_x[i] <= 800 && des_y[i] >= 100 && des_y[i] <= 280));
            }
            checker = true;
            for (int i = 0; i < 2; i++)
            {
                pickup[i] = true;
                drop[i] = false;
            }
        }
    }

    void generate() override
    {
        for (int i = 0; i < 2; i++)
        {
            while (overlap)
                overlap = false;

            per1[i] = 350 + rand() % 250;
            per2[i] = 350 + rand() % 250;

            if ((per1[i] >= 150 && per1[i] <= 300 && per2[i] >= 100 && per2[i] <= 280) ||
                (per1[i] >= 150 && per1[i] <= 300 && per2[i] >= 470 && per2[i] <= 650) ||
                (per1[i] >= 650 && per1[i] <= 800 && per2[i] >= 470 && per2[i] <= 650) ||
                (per1[i] >= 650 && per1[i] <= 800 && per2[i] >= 100 && per2[i] <= 280))
                overlap = true;
            for (int j = 0; j < i; j++)
            {
                if (abs(per1[i] - per1[j]) < 60 && abs(per2[i] - per2[j]) < 60)
                    overlap = true;
            }
        }
    }

    void drawObject() override
    {
        for (int i = 0; i < 2; i++)
        {
            if (pickup[i])
            {
                DrawCircle(per1[i], per2[i], 10, colors[RED]);
                DrawLine(per1[i], per2[i] - 10, per1[i], per2[i] - 40, 3, colors[WHITE]);
                DrawLine(per1[i], per2[i] - 40, per1[i] - 10, per2[i] - 60, 3, colors[WHITE]);
                DrawLine(per1[i], per2[i] - 40, per1[i] + 10, per2[i] - 60, 3, colors[WHITE]);
                DrawLine(per1[i], per2[i] - 25, per1[i] - 15, per2[i] - 35, 3, colors[WHITE]);
                DrawLine(per1[i], per2[i] - 25, per1[i] + 15, per2[i] - 35, 3, colors[WHITE]);
            }
        }
    }

    void DropObject() override
    {
        for (int i = 0; i < 2; i++)
        {
            if (drop[i])
            {
                DrawSquare(des_x[i], des_y[i], 30, colors[PURPLE]);
            }
        }
    }

    void PickUp() override
    {
        // Will be called with Car in Game class; implemented there
    }

    void dropPassenger(Car& c, int& score) // Helper method for dropping logic
    {
        int x = c.getX();
        int y = c.getY();
        int s = c.getSize();
        for (int i = 0; i < 2; i++)
        {
            int dx = des_x[i];
            int dy = des_y[i];
            if (drop[i] && x + s >= dx && x + s <= dx + 30 && y + s >= dy && y + s <= dy + 30)
            {
                drop[i] = false;
                score += 20;
            }
        }
    }

    void pickUpPassenger(Car& c) // Helper method for pickup logic
    {
        int x = c.getX();
        int y = c.getY();
        int s = c.getSize();
        for (int i = 0; i < 2; i++)
        {
            if (pickup[i])
            {
                int dx = per1[i];
                int dy = per2[i];
                if (x + s >= dx - 10 && x + s <= dx + 10 && y + s >= dy - 60 && y + s <= dy)
                {
                    pickup[i] = false;
                    drop[i] = true;
                }
            }
        }
    }
