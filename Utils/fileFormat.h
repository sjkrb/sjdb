#ifndef FILEFORMAT_H
#define FILEFORMAT_H

///sjdbheader
///database name length [uint8]
///database name
///database fileds
/// {
///     table count [int]
///     table 0 name char count [int]
///     table 1 name char count [int]
///     .
///     .
///     .
///     table[0] start pos [long]
///     table[1] start pos [long]
///     .
///     .
///     .
/// }
/// table fields
/// {
///     table[0] style length [uint]
///     table[0] style string
///     table[0]contents
///}
#endif // FILEFORMAT_H
