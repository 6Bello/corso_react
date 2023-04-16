import React, { useEffect, useState } from 'react';
import styles from '../style/style';
import { Button, FlatList, StyleSheet, Text, TextInput, View } from 'react-native';
import CustomButton from './components/CustomButton';

function App3() {

    const [loading, setLoading] = useState(false);

    const [data, setData] = useState([
        { label: 'elemento1' },
        { label: 'elemento2' },
    ]);

    let number = 2;

    const updateData = () => {
        number++;
        setLoading(true);
        setTimeout(() => {
            setData([{ label: 'elemento3' },{ label: 'elemento4' }]);
                // data.push({label: "elemento"+number})
                /*console.log(data)*/
            setLoading(false);
        }, 2000)     //i secondi che deve aspettare
    }

    return (
        <View style={styles.container}>
            <Text style={styles.titolo}>FLATLIST</Text>
            <Text>nelle Flatlist va passato sempre "data" e "renderItem"</Text>
            <View style={App3_style.flatListContainer}>
                <FlatList
                    data={data}
                    renderItem={Elemento}
                    onRefresh={updateData}
                    refreshing={loading}>
                </FlatList>
            </View>
        </View>
    );
}

const Elemento = ({ item }: any) => <Text style={{ color: "black" }}>{item.label}</Text>

const App3_style = StyleSheet.create({
    flatListContainer: {
        height: 200, width: '100%',
        backgroundColor: 'lightgrey',
        color: 'black'
    }
})

export default App3