int V, E;
struct Edge
{
    int a, b, c;
} edge[40000];
int d[1000], p[1000], v[1000], n[1000], m[1000];
// �C���I�̤p�J�䪺�v���A�C���I�̤p�J�䪺�ӷ��A
// ���X�L�A�������A�w���Y�C

int MST(int r)
{
    memset(m, 0, sizeof(m));

    // �ثe�ͦ����v���A�֭p���Y�������ӥ��h���v���C
    int w1 = 0, w2 = 0;
    while (true)    // �@���Φ��ͦ���N����C�̦h����V-1���C
    {
        /* O(E) graph traversal.
           find minimum in-edge for each vertice.

           --->o
        */
        memset(d, 1, sizeof(d));
        memset(p, -1, sizeof(p));

        for (int i=0; i<E; ++i)
        {
            int& a = edge[i].a;
            int& b = edge[i].b;
            int& c = edge[i].c;
            if (a != b && b != r && c < d[b])
                d[b] = c, p[b] = a;
        }

        /* O(V) jellyfish detection
             ___
            /   \
            \___/
           _/|||\_
            //1\\
        */
        memset(v, -1, sizeof(v));
        memset(n, -1, sizeof(n));

        w1 = 0;
        bool jf = false;
        for (int i=0; i<V; ++i)
        {
            if (m[i]) continue;
            if (p[i] == -1 && i != r) return 1e9;
            if (p[i] >= 0) w1 += d[i];

            // �������
            int s;
            for (s = i; s != -1 && v[s] == -1; s = p[s])
                v[s] = i;

            // �аO�������W���I�A�H�αN�|�Q���Y�����I�C
            if (s != -1 && v[s] == i)
            {
                jf = true;
                int j = s;
                do
                {
                    n[j] = s;
                    m[j] = 1;
                    w2 += d[j];
                    j = p[j];

                }
                while (j != s);
                m[s] = 0;
            }
        }
        if (!jf) break;

        /* O(E) edge reweighting and cycle contraction
             ___
            /   \ <-
            \___/
        */
        for (int i=0; i<E; ++i)
        {
            int& a = edge[i].a;
            int& b = edge[i].b;
            int& c = edge[i].c;
            if (n[b] >= 0) c -= d[b];
            if (n[a] >= 0) a = n[a];
            if (n[b] >= 0) b = n[b];
            if (a == b) edge[i--] = edge[--E];
        }
    }
    return w1 + w2;
}

