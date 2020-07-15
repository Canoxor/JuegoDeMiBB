#ifndef ITEM_H
#define ITEM_H


class item
{
    public: ///METODOS
        item();
        virtual ~item();

        void spawn();
        void despawn();

    protected:
        float x;
        float y;

    private:
};

#endif // ITEM_H
