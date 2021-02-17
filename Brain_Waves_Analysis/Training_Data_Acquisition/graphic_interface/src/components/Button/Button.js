import React from 'react';

import "./button.css";


class Button extends React.Component {

	render() {
		return (
			<div className="button">
				{this.props.children}
			</div>
		);
	}
}

export default Button;