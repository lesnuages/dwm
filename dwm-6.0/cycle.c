static void x_prevtag(const Arg *arg) {
    (void)arg;
    x_adjtag(-1);    
}

static void x_nexttag(const Arg *arg) {
    (void)arg;
    x_adjtag(+1);    
}

static void x_adjtag(int n) {
    {
        int i, curtags;
        int seltag = 0;
        Arg arg;

        /*
         *     * Check first tag currently selected.  If there are
         *         * several tags selected we only pick first one.
         *             */
        if (selmon != NULL) {
            curtags = (selmon->tagset[selmon->seltags] & TAGMASK);
        } else {
            return;
        }
        for (i = 0; i < LENGTH(tags); i++) {
            if ((curtags & (1 << i)) != 0) {
                seltag = i;
                break;
            }
        }

        /*
         *      * Calculate next selected tag wrapping around
         *           * when tag overflows.
         *                */
        seltag = (seltag + n) % (int)LENGTH(tags);
        if (seltag < 0)
            seltag += LENGTH(tags);

        arg.ui = (1 << seltag);
        view(&arg);
    }
}
