void compress_this(vll &points)
{

    sort( points.begin(), points.end() );
    points.erase( unique( points.begin(), points.end() ), points.end() );

}