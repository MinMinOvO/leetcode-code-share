

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
    long width, height;
    long A1=A, B1=B, C1=C, D1=D, E1=E, F1=F, G1=G, H1=H;
    if(A1 < E1)
    {
        if(C1 < G1)
        {
            width = C1 - E1;
            if(width < 0)
            {
                width = 0;
            }
        }
        else
        {
            width = G1 - E1;
        }
    }
    else
    {
        if(C1 < G1)
        {
            width = C1 - A1;
        }
        else
        {
            width = G1 - A1;
            if(width < 0)
            {
                width = 0;
            }
        }
    }
    if(B1 < F1)
    {
        if(D1 < H1)
        {
            height = D1 - F1;
            if(height < 0)
            {
                height = 0;
            }
        }
        else
        {
            height = H1 - F1;
        }
    }
    else
    {
        if(D1 < H1)
        {
            height = D1 - B1;
        }
        else
        {
            height = H1 - B1;
            if(height < 0)
            {
                height = 0;
            }
        }
    }
    return (C1-A1)*(D1-B1) + (G1-E1)*(H1-F1) - width*height;
}

