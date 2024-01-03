class Maze{
  private:
    int _n;
    int **labirinto;

  public:
    Maze(int n);
    ~Maze();
    void leMatriz();
    void imprimeLabirinto();
    bool VerificaSaidaLabirinto(int x, int y);
};

